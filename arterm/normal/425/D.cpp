#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 100100
#define x first
#define y second
#define mp make_pair

pair<int,int> a[M];
int n;
int kx[M],ky[M];
vector<int> x[M],y[M];

void read(void){
    cin>>n;
    for (int i=0,x1,y1; i<n; ++i){
        cin>>x1>>y1;
        a[i]=mp(x1,y1);
        x[x1].push_back(y1);
        y[y1].push_back(x1);
    }
    sort(a,a+n);
    for (int i=0; i<M; ++i){
        sort(x[i].begin(),x[i].end());
        sort(y[i].begin(),y[i].end());
    }
}

void kill(void){
    int ans=0;
    
    for (int i=0; i<n; ++i){
        int x1=a[i].x;
        int y1=a[i].y;
        ++kx[x1];
        ++ky[y1];
        int d;
        if (x[x1].size()<y[y1].size())
            for (int j=kx[x1]; j<(int)x[x1].size(); ++j){
                d=x[x1][j]-y1;
                if (binary_search(y[y1].begin(),y[y1].end(),x1+d) && binary_search(y[y1+d].begin(),y[y1+d].end(),x1+d))
                ++ans;
            }
        else
            for (int j=ky[y1]; j<(int)y[y1].size(); ++j){
                d=y[y1][j]-x1;
                if (binary_search(x[x1].begin(),x[x1].end(),y1+d) && binary_search(x[x1+d].begin(),x[x1+d].end(),y1+d))
                ++ans;
        }
        
    }
    
    cout<<ans<<"\n";
}
        

int main()
{
#ifdef TROLL
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();
    
    return 0;
}