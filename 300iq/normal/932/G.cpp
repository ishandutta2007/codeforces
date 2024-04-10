#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const int mod = 1e9 + 7;
char s[N],t[N],S[N];
int n,go[N][26],len[N],par[N],top,last;
int New(int L){len[++top]=L;return top;}
int diff[N],slink[N];
void extend(int n){
	int w=S[n],p=last;
	while (S[n-len[p]-1]!=w) p=par[p];
	if (!go[p][w-'a']){
		int q=New(len[p]+2),now=p;
		do now=par[now];while (S[n-len[now]-1]!=w);
		par[q]=go[now][w-'a'];
		go[p][w-'a']=q;
		diff[q]=len[q]-len[par[q]];
		slink[q]=(diff[q]==diff[par[q]]?slink[par[q]]:par[q]);
	}
	last=go[p][w-'a'];
}
int ans[N],from[N],_ans[N], sum[N];
char kek[N];
int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    scanf("%s", kek + 1);
    int n = strlen(kek + 1);
    for (int i = 1; i <= n / 2; i++) s[i] = kek[i];
    for (int i = 1; i <= n / 2; i++) t[i] = kek[n - i + 1];
	n /= 2;
	for (int i=1;i<=n;i++) S[i*2-1]=s[i],S[i*2]=t[i];
	par[0]=top=1;len[1]=-1;
	n*=2;
	for (int i=1;i<=n;i++) ans[i]=0;
	_ans[0]= 1;
    ans[0] = 1;
	for (int i=1;i<=n;i++){
		extend(i);
		for (int p=last;p;p=slink[p]){
			_ans[p]=i-(len[slink[p]]+diff[p]);
            sum[p] = ans[_ans[p]];
            int cur = p;
            if (diff[par[cur]]==diff[cur])
            {
                sum[cur] += sum[par[cur]];
                if (sum[cur] >= mod) sum[cur] -= mod;
            }
            if (!(i & 1))
            {
                ans[i] += sum[cur];
                if (ans[i] >= mod) ans[i] -= mod;
            }
			
		}
	}
    cout << ans[n] << '\n';
}