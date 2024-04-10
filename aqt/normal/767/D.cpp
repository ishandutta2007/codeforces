#include <bits/stdc++.h>

using namespace std;

int N, M, K;
pair<int, int> arr2[1000005];
int arr1[1000005];
vector<int> ans;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i =1; i<=N; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i =1 ; i<=M; i++){
        scanf("%d", &arr2[i].first);
        arr2[i].second = i;
    }
    sort(arr1, arr1+N+1);
    sort(arr2, arr2+M+1);
    int idx1 = N, idx2 = M;
    arr1[0] = -1;
    for(int i = 10000000; i>=0; i--){
        int cnt = K;
        while(arr1[idx1] >= i && cnt){
            idx1--;
            cnt--;
        }
        while(cnt && idx2 > 0 && arr2[idx2].first >= i){
            ans.push_back(arr2[idx2].second);
            cnt--;
            idx2--;
        }
    }
    if(idx1){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans.size());
    for(int n : ans){
        printf("%d ", n);
    }
}