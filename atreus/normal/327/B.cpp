#include <bits/stdc++.h>

using namespace std;

bool mark[10001000];

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    mark[1] = true;
    for (int i = 2; i <= 2000000; i++){
        if (mark[i] == false){
            for (int j = i + i; j <= 2000000; j += i){
                mark[j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 5000000; i++){
        if (mark[i] == false){
            cout << i << " ";
            cnt ++;
        }
        if (cnt >= n)
            return 0;
    }

}