#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string v[2][100005];
int chosen[100005];
int p[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    int n=0;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[0][i]>>v[1][i];
        if(v[0][i]>v[1][i])
            swap(v[0][i],v[1][i]);
        //cout<<"am citit "<<v[0][i]<<' '<<v[1][i]<<endl;
    }

    for(int i=1;i<=n;i++)
        cin>>p[i];

    chosen[p[1]]=0;
    for(int i=2;i<=n;i++){
        if(v[0][p[i]]>v[chosen[p[i-1]]][p[i-1]])
            continue;
        if(v[1][p[i]]>v[chosen[p[i-1]]][p[i-1]]){
            chosen[p[i]]=1;
            continue;
        }

        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    return 0;
}