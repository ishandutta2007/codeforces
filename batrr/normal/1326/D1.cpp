#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1000500;
 
char s[N], t[N];
int n, m, d1[N], d2[N], L, R, A, B;
void solve(){
	scanf("%s", s);
	n = strlen(s);
	L = 0, R = n - 1;
	for(int i = 0; i < n; i++){
		if(i < n - 1 - i && s[i] == s[n - 1 - i])
			continue;
		L = i;
		R = n - 1 - i;
		break;
	}
	if(L >= R){
		for(int i = 0; i < n; i++)
			printf("%c", s[i]);
		printf("\n");
		return;
	}
	m = 0;
	for(int i = L; i <= R; i++)
		t[m++] = s[i];
    A = B = 0;
	vector<vector<int>> p(2,vector<int>(m,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
        for(int i=0;i<m;i++)
        {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            int L=i-p[z][i], R=i+p[z][i]-!z;
            while(L-1>=0 && R+1<m && t[L-1]==t[R+1]) p[z][i]++,L--,R++;
            if(R>r) l=L,r=R;
        	if(L == 0 || R == m - 1){
        		if(R - L > B - A)
        			A = L, B = R;
        	}
        }
	for(int i = 0; i < L; i++)
		printf("%c", s[i]);
	for(int i = A; i <= B; i++)
		printf("%c", t[i]);
	for(int i = R + 1; i < n; i++)
		printf("%c", s[i]);
	printf("\n");
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}