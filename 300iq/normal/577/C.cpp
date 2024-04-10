#include <iostream>
#define ll long long
using namespace std;
bool easy(int n){
for(int i = 2; i<n; i++){
    if(n%i==0){
    return false;
    }
}
return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int t = 1;
    int counter = 0;
    if(n==2){
        cout<<1<<endl<<2;
        return 0;
    }
    for(int i = 2; i <= n; i++){
        t = 1;
        if(easy(i)){
            while(t*i<=n){
                t*=i;
                arr[counter] = t;
                counter++;
            }
        }
    }
    cout<<counter<<endl;
    for(int i = 0; i<counter; i++){
        cout<<arr[i]<<" ";
    }

}