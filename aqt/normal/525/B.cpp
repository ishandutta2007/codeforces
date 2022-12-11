#include <bits/stdc++.h>

using namespace std;

string s;
int N;
int arr[100005];
char ans[200005];

int main(){
    cin >> s;
    cin >> N;
    for(int i =1; i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int i =1; i<=(s.size()+1)/2; i++){
        arr[i] += arr[i-1];
        if(arr[i]%2){
            ans[i] = s[s.size()-i];
            ans[s.size()-i+1] = s[i-1];
        }
        else{
            ans[i] = s[i-1];
            ans[s.size()-i+1] = s[s.size()-i];
        }
    }
    for(int i = 1; i<=s.size(); i++){
        cout << ans[i];
    }
}