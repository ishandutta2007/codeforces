#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;


template <typename T>
constexpr bool is_tuple = false;

template<typename ... types>
constexpr bool is_tuple<tuple<types...>> = true;

template<typename A, typename B>
constexpr bool is_tuple<pair<A, B>> = true;

	
template<typename T> struct IsContainer { 
	typedef typename remove_const<T>::type test_type;
	template<typename A> static constexpr bool test(A* pt, decltype(pt->begin())* = nullptr, decltype(pt->end())* = nullptr) 
	{ return is_same<decltype(pt->begin()),typename A::iterator>::value && is_same<decltype(pt->end()),typename A::iterator>::value; }
	template<typename A> static constexpr bool test(...) { return false; }
	static constexpr bool value = test<test_type>(nullptr);
};

template<typename T>
constexpr bool is_container = IsContainer<T>::value;


template <typename T>
constexpr bool is_string = is_same<T, string>::value;

template<typename>
struct to_mutable { };

template<typename... Ts>
struct to_mutable<tuple<Ts...>> {
    using type = tuple<typename remove_cv<Ts>::type...>;
};

template<typename... Ts>
struct to_mutable<pair<Ts...>> {
    using type = pair<typename remove_cv<Ts>::type...>;
};


string readline() { string value; getline(cin, value); return value; }

template<typename T, typename ...Args> typename enable_if<!is_tuple<T> && (!is_container<T> || is_string<T>), T>::type read() {
	T value;
	cin >> value;
	return value;
}

template<typename T, typename ...Args> typename enable_if<is_tuple<T>, T>::type read(Args ...args);
template<typename T, typename ...Args> typename enable_if<is_container<T>, T>::type read(size_t N, Args... args);

template<typename T> typename enable_if<is_container<T> && !is_string<T>, T>::type read() { 
	size_t N = read<size_t>();
	return read<T>(N);
}

template<typename X, size_t I = 0, typename ...Args, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, typename to_mutable<X>::type>::type read_tuple(Args... args) { return typename to_mutable<X>::type(); }

template<typename X, size_t I = 0, typename ...Args, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, typename to_mutable<X>::type>::type read_tuple(Args... args) {
	auto tmp = read<typename tuple_element<I, typename to_mutable<X>::type>::type>(args...);
	typename to_mutable<X>::type value = read_tuple<X, I + 1>(args...);
	get<I>(value) = tmp;
	return value;
}

template<typename T, typename ...Args> typename enable_if<is_tuple<T>, T>::type read(Args... args) { return read_tuple<T>(args...); }

template<typename T, typename ...Args> typename enable_if<is_container<T>, T>::type read(size_t N, Args... args) { 
	T container;
	for(size_t i = 0;i < N;i++) { 
		*inserter(container, container.end()) = read<typename T::value_type>(args...);
	}
	return container;
}


void flush() { cout << flush; }

void writesp() { cout << " "; }
void writeln() { cout << "\n"; }

template<typename T> void writesp(const T& value);
template<typename T> void writeln(const T& value);

template<typename T, typename enable_if<!is_container<T> && !is_tuple<T>, T>::type* = nullptr> 
void write(const T& value) { cout << value; }
void write(const string& value) { cout << value; }
void write(const char* value) { cout << value; }

template<typename T, typename enable_if<is_container<T>, T>::type* = nullptr> void writerow(const T& value) { 
	typedef typename T::const_iterator It; 
	for(It it = value.begin();it != value.end();it++) { writesp(*it); }
}

template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, void>::type writerow(const X& t) {}
template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, void>::type writerow(const X& t) { writesp(get<I>(t)); writerow<I + 1>(t); }

template<typename T, typename enable_if<is_container<T>, T>::type* = nullptr> void writecol(const T& value) { 
	typedef typename T::const_iterator It; 
	for(It it = value.begin();it != value.end();it++) { writeln(*it); }
}

template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, void>::type writecol(const X& t) {}
template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, void>::type writecol(const X& t) { writesp(get<I>(t)); writerow<I + 1>(t); }

template<typename T, typename enable_if<!is_container<typename T::value_type> && !is_tuple<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { writerow(value); }
template<typename T, typename enable_if<is_tuple<T>, T>::type* = nullptr> void write(const T& value) { writerow(value); }

template<typename T> void write2d(const T& value) {
	typedef typename T::const_iterator It; 
	for(It it = value.begin();it != value.end();it++) { writeln(*it); }
}

template<typename T, typename enable_if<is_container<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { write2d(value); }
template<typename T, typename enable_if<is_tuple<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { write2d(value); }

template<typename T> void writesp(const T& value) { write(value); writesp(); }
template<typename T> void writeln(const T& value) { write(value); writeln(); }


void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

template<typename T>
struct Multiply {
	T value;
	Multiply(T _value) { value = _value; };
	T operator() (const T& mult) {
		return value * mult;
	}
};

template<typename T>
struct Different {
	T value;
	Different(T _value) { value = _value; };
	bool operator() (const T& other) {
		return other != value;
	}
};

template<typename T>
struct Equal {
	T value;
	Equal(T _value) { value = _value; };
	bool operator() (const T& other) {
		return other == value;
	}
};

template<typename T>
struct Abs {
	T operator() (const T& value) {
		return abs(value);
	}
};



template<typename T>
typename enable_if<is_container<T>, T>::type operator + (const T& a, const T& b) {
	T container;

	auto itA = a.begin();
	auto itB = b.begin();

	while(itA != a.end() && itB != b.end()) {
		typename T::value_type sum(0);
		if(itA != a.end()) {
			sum += *itA;
			itA++;
		}
		if(itB != b.end()) {
			sum += *itB;
			itB++;
		}
		*inserter(container, container.end()) = sum;
	}

	return container;
}

template<typename T>
typename enable_if<is_container<T>, T>::type operator * (const typename T::value_type& a, const T& x) {
	return apply_function(x, Multiply(a));
}

template<typename T>
typename enable_if<is_container<T>, T>::type operator - (const T& a, const T& b) {
	return a + -1 * b;
}

template<typename T, typename F>
typename enable_if<is_container<T>, T>::type apply_function(const T& x, F f) {
	T container;
	for(auto it = x.begin();it != x.end();it++) {
		*inserter(container, container.end()) = f(*it);
	}
	return container;
}

template<typename T, typename F>
typename enable_if<is_container<T>, T>::type filter(const T& x, F f) {
	T container;
	for(auto it = x.begin();it != x.end();it++) {
		if(f(*it))
			*inserter(container, container.end()) = *it;
	}
	return container;
}

template<typename T, typename F>
typename enable_if<is_container<T>, size_t>::type count(const T& x, F f) {
	return filter(x, f).size();
}

template<typename T>
auto keys(const T& v) {
	vector<typename remove_cv<typename tuple_element<0, typename T::value_type>::type>::type> res;
	for(auto it = v.begin();it != v.end();it++) {
		*inserter(res, res.end()) = get<0>(*it);
	}
	return res;
}

template<typename T>
auto values(const T& v) {
	vector<typename remove_cv<typename tuple_element<1, typename T::value_type>::type>::type> res;
	for(auto it = v.begin();it != v.end();it++) {
		*inserter(res, res.end()) = get<1>(*it);
	}
	return res;
}

template<typename T>
typename enable_if<is_container<T>, typename T::value_type>::type sum(const T& a) { 
	if(a.empty()) return typename T::value_type();
	auto s = *a.begin();
	auto it = a.begin(); it++;
	for(;it != a.end();it++) {
		s = s + *it;
	}
	return s; 
}

template<typename T>
typename enable_if<is_container<T>, typename T::value_type>::type max(const T& a) { return *max_element(a.begin(), a.end()); }
template<typename T>
typename enable_if<is_container<T>, typename T::value_type>::type min(const T& a) { return *min_element(a.begin(), a.end()); }

template<typename T>
T sorted(T a) { sort(a.begin(), a.end()); return a; }
template<typename T>
T reversed(T a) { reverse(a.begin(), a.end()); return a; }

template<typename T>
T concat(T a, const T& b) {
	for(auto it = b.begin();it != b.end();it++) {
		*inserter(a, a.end()) = *it;
	}
	return a;
}

vector<int> range(int deb, int fin) {
	vector<int> res;
	for(int i = deb;i < fin;i++) {
		res.push_back(i);
	}
	return res;
}

template<typename T>
auto cut(const T& v) {
	vector<pair<typename T::value_type, size_t>> res;
	for(auto it = v.begin();it != v.end();it++) {
		if(res.empty() || res.back().first != *it) res.push_back({*it, 1});
		else res.back().second++;
	}
	return res;
}

template<typename T>
bool is_subsequence(const T& a, const T& b) {
	auto itA = a.begin();
	for(auto itB = b.begin();itB != b.end();itB++) {
		if(itA == a.end()) return true;
		if(*itA == *itB) itA++;
	}
	return itA == a.end();
}

template<typename T>
auto norme_inf(const T& a) {
	return sum(apply_function(a, Abs<typename T::value_type>()));
}


set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
vector<string> answers = {"NO", "YES"};

void y_not_vowel() { vowels.erase('y'); }
bool is_vowel(char car) { return vowels.find(car) != vowels.end(); }
char to_lower(char car) { return tolower(car); }
char to_upper(char car) { return toupper(car); }
string to_lower(const string& s) { return apply_function<string, char (*)(char)>(s, to_lower); }
string to_upper(const string& s) { return apply_function<string, char (*)(char)>(s, to_upper); }
bool is_upper(char car) { return car >= 'A' && car <= 'Z'; }
bool is_lower(char car) { return car >= 'a' && car <= 'z'; }
char switch_case(char car) { if(is_upper(car)) return to_lower(car); if(is_lower(car)) return to_upper(car); return car; }

string replace(string s, const string& pattern, const string& replacement) {
	size_t pos = s.find(pattern);
	while(pos != std::string::npos) {
		s.replace(pos, pattern.size(), replacement);
		pos = s.find(pattern, pos + replacement.size());
	}
	return s;
}


template<typename I>
I div_up(I a, I b) {
	return (a + b - 1) / b;
}

template<typename I>
vector<I> divisors(I a) {
	vector<I> lowDivs, upDivs;
	for(I d = 1;d * d <= a;d++) {
		if(a % d == 0) {
			lowDivs.push_back(d);
			if(d * d != a)
				upDivs.push_back(a / d);
		}
	}
	return concat(lowDivs, reversed(upDivs));
}


vector<int> reverse_permutation(vector<int> perm) {
	vector<int> res(perm.size(), 0);
	for(size_t i = 0;i < perm.size();i++) {
		res[perm[i]] = i;
	}
	return res;
}


int main() {
	fast_io();

	int taille = read<int>();
	int nombre = read<int>();

	int res = 0;
	for(int i : range(1, taille + 1)) {
		if(nombre % i == 0 && nombre / i <= taille)
			res++;
	}
	writeln(res);
	return 0;
}