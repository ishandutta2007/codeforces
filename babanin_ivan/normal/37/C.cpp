#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n;
pair<int,int> a[2000];
bool b[2000][2000];
int pz[1000];

int main(){
    scanf("%d/n",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }   
    sort(a,a+n);
    for (int i=0; i<1001;++i)
        b[0][i]=false;
    for (int i=1;i<n;++i){
        for (int j=0;j<1000;++j)
            b[i][j]=b[i-1][j];
        bool ok=false;
        for (int j=a[i-1].first-1;j>=0;j--)
            if (!b[i][j]){
                b[i][j]=true;
                ok=true;
                break;
            }
            else b[i][j]=false;
        if (!ok){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<n;++i)
        pz[a[i].second]=i;
    for (int i=0;i<n;++i){
        for (int j=0;j<a[pz[i]].first;++j)
            if (b[pz[i]][j])
              printf("%d",1);
            else printf("%d",0); 
        printf("\n");
    }
}