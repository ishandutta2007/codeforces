#include <bits/stdc++.h>

using namespace std;

bool has[1000005];

int main(){
    int N;
    cin >> N;
    int lst = N, crnt = N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        has[n] = 1;
        while(has[crnt]){
            printf("%d ", crnt);
            crnt--;
        }
        printf("\n");
    }
}