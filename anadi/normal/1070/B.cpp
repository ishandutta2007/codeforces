#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;

int n;
set <PLL> S[2];
vector <PLL> res;

PLL get(PLL a, PLL b){
	if(b.st < a.st)
		swap(a.st, b.st);
	
	if(a.nd >= b.nd)
		return a;
	
	LL cm = 0;
	while((a.st & (1LL << (31 - cm))) == (b.nd & (1LL << (31 - cm))))
		++cm;
	
	a.st >>= 32 - cm;
	a.st <<= 32 - cm;
	return {a.st, a.st + (1LL << (32 - cm)) - 1};
}

void add(int t, PLL a){
	while(S[t].size()){
		auto it = S[t].lower_bound(a);
		if(it != S[t].end() && (*it).st <= a.nd + 1){
			a.nd = max(a.nd, (*it).nd);
			S[t].erase(it);
			continue;
		}
		
		if(it != S[t].begin()){
			--it;
			if((*it).nd >= a.st){
				a.st = (*it).st;
				a.nd = max(a.nd, (*it).nd);
				S[t].erase(it);
				continue;
			}
		}
		
		break;
	}
	
	S[t].insert(a);
}

void read(){
	string s;
	cin >> s;
	
	int t = s[0] == '+' ? 1 : 0;	
	LL p = 0LL, k = 1; int lst = s.size();
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '/'){
			LL x = 0;
			for(int j = i + 1; j < s.size(); ++j)
				x *= 10, x += s[j] - '0';
			
			lst = i;
			k = 1LL << (32 - x);
			break;
		}
	
	for(int i = 1; i < s.size(); ++i){
		int nxt = lst;
		for(int j = i; j < nxt; ++j)
			if(s[j] == '.'){
				nxt = j;
				break;
			}
			
		LL cur = 0LL;
		for(int j = i; j < nxt; ++j)
			cur *= 10, cur += s[j] - '0';
		
		p += cur;
		if(nxt < lst)
			p *= 256;
		else
			break;
		i = nxt;
	}
	
	if(t == 1)
		add(t, {p, p + k - 1});
	else
		S[t].insert({p, p + k - 1});
}

bool check(PLL a){
	if(S[1].size() == 0)
		return true;

	auto it = S[1].lower_bound(a);
	if(it != S[1].end() && (*it).st <= a.nd)
		return false;
	if(it != S[1].begin() && (*(--it)).nd >= a.st)
		return false;
	return true;
}

void write(PLL a){
	a.nd -= a.st - 1;
	int pt = 0;
	while((1LL << pt) < a.nd)	++pt;

	printf("%lld.%lld.%lld.%lld/%d\n", a.st / (1 << 24), (a.st%(1 << 24)) / (1 << 16), (a.st%(1 << 16)) / (1 << 8), a.st%(1 << 8), 32 - pt);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		read();
	
	for(auto v: S[0])
		if(!check(v)){
			puts("-1");
			return 0;
		}
	
	PLL last = *S[0].begin();
	S[0].erase(S[0].begin());

	while(S[0].size()){
		if(check(get(last, *S[0].begin())))
			last = get(last, *S[0].begin());
		else{
			res.push_back(last);
			last = *S[0].begin();
		}

		S[0].erase(S[0].begin());
	}
	
	res.push_back(last);
	printf("%d\n", res.size());
	
	for(auto v: res)
		write(v);
	return 0;
}