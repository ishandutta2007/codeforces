#include <bits/stdc++.h>
#define maxn 110
#define pii pair<int,int>
#define pb push_back
using namespace std;

int foi[maxn];
int v[maxn*maxn];

int main() {
    
    int n,k;
    scanf("%d%d",&n,&k);
    
    map<int,int> last;
    int cnt = 0;
    int b = n / (k-1);
    if(n % (k-1)) b++;
    
    vector<pii> ans;
    
    for(int i=1;i<=n*k;i++){
        int a;
        scanf("%d",&a);
        v[i] = a;
        if(last[a] && !foi[a]){
            ans.pb({last[a],i});
            cnt++;
            foi[a] = 1;
            if(cnt % b == 0)
                last.clear();
        }
        else
            last[a] = i;
    }
    
    sort(ans.begin(), ans.end(), [](pii i,pii j){
        return v[i.first] < v[j.first];
    });
    
    for(pii i : ans)
        printf("%d %d\n",i.first,i.second);
    
}