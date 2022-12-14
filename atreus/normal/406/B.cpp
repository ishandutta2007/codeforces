#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int a[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mark[a[i]] = 1;
	}
	int s = 1000000;
	vector<int> opt;
	int ptr = 1;
	for (int i = 0; i < n; i++){
		if (!mark[s-a[i]+1]){
			opt.push_back(s-a[i]+1);
			mark[s-a[i]+1] = 1;
		}
		else if (a[i] <= s/2){
			while (mark[ptr] or mark[s-ptr+1])
				ptr ++;
			opt.push_back(ptr);
			opt.push_back(s-ptr+1);
			ptr ++;
		}
	}
	printf("%d\n", (int)opt.size());
	for (auto it : opt)
		printf("%d ", it);
	printf("\n");
}