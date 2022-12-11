#include <bits/stdc++.h>

using namespace std;

int arr[300005];
bool val[300005];
int N;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int idx = N+1;
    printf("%d ", 1);
    for(int i = 1; i<=N; i++){
        val[arr[i]] = 1;
        while(val[idx-1]){
            idx--;
        }
        printf("%d ", (i)-(N+1-idx)+1);
    }
}