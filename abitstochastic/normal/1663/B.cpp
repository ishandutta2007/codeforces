#include<bits/stdc++.h>
using namespace std;
 
int arr[] = {1200,1400,1600,1900,2100,2300,2400,2600,3000};
 
int main(){
    int x; cin >> x;
    while(find(arr,arr+9,++x) == arr+9);
    cout << x;
    return 0;
}