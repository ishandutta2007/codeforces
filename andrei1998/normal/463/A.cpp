#include <iostream>
#include <algorithm>

using namespace std;

int x[105];
int y[105];
int n;

int main()
{
    cin>>n;
    int s=0;
    cin>>s;

    for(int i=1;i<=n;i++){
        cin>>x[i];
        cin>>y[i];
    }

    int maxim=-1;
    for(int i=1;i<=n;i++){
        if(y[i]==0){
            if(x[i]<=s){
                maxim=max(maxim,0);
            }
        }
        else{
            if(x[i]<s){
                maxim=max(maxim,100-y[i]);
            }
        }
    }

    cout<<maxim<<'\n';
    return 0;
}