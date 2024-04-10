#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[200005];
int arr[200005];
bool tkn[200005];
queue<int> qu;

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i = 1; i<=N; i++){
        if(!cnt[i]){
            qu.push(i);
        }
    }
    cout << qu.size() << endl;
    for(int i = 1;i <=N; i++){
        if(tkn[arr[i]]){
            cnt[arr[i]]--;
            arr[i] = qu.front();
            cnt[arr[i]]++;
            qu.pop();
        }
        else if(qu.size() && qu.front() < arr[i] && cnt[arr[i]] > 1){
            cnt[arr[i]]--;
            arr[i] = qu.front();
            cnt[arr[i]]++;
            qu.pop();
        }
        else {
        }
        tkn[arr[i]] = 1;
        cout << arr[i] << " ";
    }
}