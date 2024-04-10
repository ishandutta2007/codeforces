#include <iostream>
#include <algorithm>

using namespace std;

int n;
int L[100000+10];

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>L[i];
    }
    int ans=0,c=1;
    for (int i=1; i<n; i++){
        if (L[i]<L[i-1]){
            ans=max(ans,c);
            c=1;
        }
        else{
            c++;
        }
    }

    cout<<max(ans,c)<<endl;
    return 0;
}