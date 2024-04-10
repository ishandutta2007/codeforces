#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[100005];
vector<long long> rect;

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N, greater<int>());
    long long tot = 0, lst = 0;
    for(int i = 1; i<=N-1; i++){
        if(arr[i+1] + 1 >= arr[i]){
            if(lst){
                tot += arr[i+1]*lst;
                lst = 0;
            }
            else{
                lst = arr[i+1];
            }
            i++;
        }
    }
    cout << tot << endl;
}