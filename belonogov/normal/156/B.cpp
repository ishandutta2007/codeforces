#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = (int)1e5;

int a[maxn];
int p[maxn];
int mi[maxn];
bool use1[maxn];
bool use[maxn];


int main(){
    int n, m, i, sum = 0, cnt = 0;
    char ch;
    scanf("%d%d\n", &n, &m);
    for (i = 0; i < n; i++){
        scanf("%c%d\n", &ch, &a[i]);
        a[i]--;
        if (ch == '+'){
            p[a[i]]++;
            use1[i] = true;
        }
        if (ch == '-'){
            mi[a[i]]++;
            use1[i] = false;
            sum++;
        }
    }


    for (i = 0; i < n; i++)
        if (sum + p[i] - mi[i] == m){
            use[i] = true;
            cnt++;
        }
    
    for (i = 0;  i < n; i++){
        if (use1[i] == true){
            if (use[a[i]] == true && cnt == 1){
                cout << "Truth\n";
                continue;
            }
            if (use[a[i]] == true && cnt > 1){
                cout << "Not defined\n";
                continue;
            }
            cout << "Lie\n";
            continue;
        }
        if (use1[i] == false){
            if (use[a[i]] == false){
                cout << "Truth\n";
                continue;
            }
            if (use[a[i]] == true && cnt > 1){
                cout << "Not defined\n";
                continue;
            }
            cout << "Lie\n";
            continue;
    
        }
    }

    return 0;
}