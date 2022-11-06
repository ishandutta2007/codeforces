// a modification of ecnerwala's solution
#include <bits/stdc++.h>

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

template <typename T> struct range_val {
	T lo, hi;
	range_val() : lo(), hi( ){}
	range_val(T lo_, T hi_) : lo(lo_), hi(hi_) {}

	friend std::istream& operator >> (std::istream& i, range_val& v) { return i >> v.lo >> v.hi; }
	friend std::ostream& operator << (std::ostream& o, range_val v) { return o << v.lo << '-' << v.hi; }

	friend bool operator == (range_val a, range_val b) { return a.lo == b.lo && a.hi == b.hi; }

	explicit operator bool() const { return lo <= hi; }

	range_val operator + () const { return range_val(lo, hi); }
	range_val operator - () const { return range_val(-hi, -lo); }
	friend range_val operator + (range_val a, range_val b) { return range_val(a.lo + b.lo, a.hi + b.hi); }
	friend range_val operator - (range_val a, range_val b) { return a + (-b); }

	range_val& operator &= (const range_val& o) { setmax(lo, o.lo); setmin(hi, o.hi); return *this; }
	friend range_val operator & (range_val a, range_val b) { return range_val(max(a.lo, b.lo), min(a.hi, b.hi)); }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<range_val<int64_t>> X(N); for (auto& a : X) cin >> a;
		vector<range_val<int64_t>> Y(N-1); for (auto& a : Y) cin >> a;
		vector<range_val<int64_t>> Z(N-2); for (auto& a : Z) cin >> a;
		cout << ([&]() -> bool {
			for (int z = 0; true; z++) {
				if (z > 60) return false;
				auto old_X = X;
				auto old_Y = Y;
				auto old_Z = Z;
				for(int i = 0; i <= N-2; i++){
					Y[i] &= X[i+1] - X[i];		
					if(i >= 1) Y[i] &= Y[i-1] + Z[i-1];		
					X[i+1] &= X[i] + Y[i];
					if(i <= N-3) Z[i] &= Y[i+1] - Y[i];
				}
				for(int i = N-2; i >= 0; i--){
					Y[i] &= X[i+1] - X[i];		
					if(i <= N-3) Y[i] &= Y[i+1] - Z[i];		
					X[i] &= X[i+1] - Y[i];
					if(i >= 1) Z[i-1] &= Y[i] - Y[i-1];
				}

				if (X == old_X && Y == old_Y && Z == old_Z) break;

				for (auto& v : X) if (!v) return false;
				for (auto& v : Y) if (!v) return false;
				for (auto& v : Z) if (!v) return false;
			}

			return true;
		}() ? "YES" : "NO") << '\n';
	}

	return 0;
}