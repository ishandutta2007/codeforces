#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int n;
int group[N];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	for(auto c: s){
		if(t.size() == 0 || c != t.back())
			t.push_back(c);
		group[t.size() - 1]++;
	}
	
	n = t.size();
	if(n % 2 == 0){
		puts("0");
		exit(0);
	}
	
	int p = n / 2;
	if(group[p] < 2){
		puts("0");
		exit(0);
	}

	for(int r = 1; r <= p; ++r)
		if(group[p - r] + group[p + r] < 3 || t[p - r] != t[p + r]){
			puts("0");
			exit(0);
		}
	
	printf("%d\n", group[p] + 1);
	return 0;
}