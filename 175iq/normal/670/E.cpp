#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }
 
const int N = 500000+7;
 
int n,m,p;
char str[N];
char op[N];
char out[N];
int Q[N];
int nn[N];
int pp[N];
int pairi[N];
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&p);
    scanf("%s", str);
    scanf("%s", op);
 
    for(int i=0; i<n; i++)
        nn[i] = i+1;
    for(int i=0; i<n; i++)
        pp[i] = i-1;
 
 
    int w = -1;
    for(int i=0; i<n; i++){
        if (str[i]=='(')
            Q[++w] = i;
        else{
            int q = Q[w--];
            pairi[q] = i;
            pairi[i] = q;
        }
    }
 
    int pos = p-1;
    int start = 0;
    int eend = n-1;
    for(int i=0; i<m; i++){
        if (op[i]=='R')
            pos = nn[pos];
        else if (op[i]=='L')
            pos = pp[pos];
        else{
            int after = max(pairi[pos], pos);
            int left = min(pairi[pos], pos);
            after = nn[after];
            if (left==start){
                start = after;
                pos = after;
                pp[pos] = -1;
                continue;
            }
 
            if (after<=eend){
                nn[pp[left]] = after;
                pp[after] = pp[left];
                pos = after;
            }
            else{
                nn[pp[left]] = n;
                pos = pp[left];
                eend = pos; //?
            }
        }
    }
 
    int u = 0;
    for(int i=start; i<=eend && i>=0;){
        //printf("%c",str[i]);
        out[u++] = str[i];
        i = nn[i];
    }
    out[u] = 0;
    printf("%s",out);
	  return 0;
}