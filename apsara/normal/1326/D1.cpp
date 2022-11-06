#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 1000100;
void e_kmp(char *s,char *t,int *has,int *e_has)
{
	int sp,p,mx,tn;
	for(sp=p=mx=0;s[p]>0;p++)
	{
		if(mx==p||p+e_has[p-sp]>=mx )
		{
			for(tn=mx-p;s[mx]==t[tn];tn++)mx++;
			has[sp=p]=mx-p;
			if(mx==p)sp=++mx;
		}
		else has[p]=e_has[p-sp];
	}
}

int e_has[V],has[V],tn;
char ss[V], s[V], t[V];
int _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", ss);
        int m = strlen(ss);
        int L = -1;
        for (int i = 0; i + 1 < m - i - 1; ++i) {
            if (ss[i] != ss[m - i - 1]) break;
            L = i;
        }
        tn = m - 2 * (L + 1);
        for (int i = 0; i < tn; ++i) s[i] = ss[i + L + 1];
        for (int i = 0; i < tn; ++i) t[i] = s[tn - i - 1];
        s[tn] = t[tn] = 0;
        s[tn + 1] = t[tn + 1] = 0;
        t[tn]=-1;
        e_has[0] = tn;
        e_kmp(t+1,t,e_has+1,e_has);
        e_kmp(s,t,has,e_has);
        //printf("%s %s\n", s, t);
        //for (int i = 0; i < tn; ++i) printf("%d ", has[i]);puts("");
        int mr = 0;
        for (int i = 0; i < tn; ++i) if (has[i] >= tn - i) mr = max(mr, has[i]);
        e_has[0] = tn;
        e_kmp(s+1,s,e_has+1,e_has);
        e_kmp(t,s,has,e_has);
        //for (int i = 0; i < tn; ++i) printf("%d ", has[i]);puts("");
        int ml = 0;
        for (int i = 0; i < tn; ++i) if (has[i] >= tn - i) ml = max(ml, has[i]);
        //printf("%d %d\n", ml, mr);
        for (int i = 0; i <= L; ++i) printf("%c", ss[i]);
        if (ml > mr) {
            for (int i = 0; i < ml; ++i) printf("%c", ss[i + L + 1]);
        } else {
            for (int i = 0; i < mr; ++i) printf("%c", ss[m - L - 1 - mr + i]);
        }
        for (int i = L; i >=0; --i) printf("%c", ss[m - i - 1]); puts("");
    }
    return 0;
}

/*
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
*/