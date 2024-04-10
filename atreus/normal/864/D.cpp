#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
int a[maxn + 100], arr[maxn + 100];
bool mark[maxn + 100];
stack <int> s;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        arr[a[i]] ++;
    for (int i = n; i >= 1; i--)
        if (arr[i] == 0)
            s.push(i);
    int k = 0;
    if (!s.empty()){
        for (int i = 1; i <= n; i++){
            if (s.empty())
                break;
            if (mark[a[i]] == true){
                arr[a[i]] --;
                a[i] = s.top();
                s.pop();
                k ++;
                continue;
            }
            if (arr[a[i]] > 1){
                if (a[i] > s.top()){
                    arr[a[i]] --;
                    a[i] = s.top();
                    s.pop();
                    k ++;
                    continue;
                }
                else{
                    mark[a[i]] = true;
                    arr[a[i]] --;
                    continue;
                }
            }
        }
    }
    cout << k << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}