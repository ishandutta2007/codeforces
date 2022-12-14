#include <iostream>


using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = n; i >= 1; i--){
        if (a[i] == 0)
            cnt ++;
        else
            break;
    }
    if (cnt == 0){
        cout << "NO" << endl;
        return 0;
    }
    if (cnt == 2){
        int k = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 0)
                k ++;
        if (k == 2){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        int l;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1)
                cout << 1 << "->";
            else{
                cout << 0 << "->(";
                l = i + 1;
                break;
            }
        }
        for (int i = l; i <= n - 1; i++){
            if (i != l)
                cout << "->";
            cout << a[i];
        }
        cout << ")->0" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (cnt == 1){
        cout << a[1];
        for (int i = 2; i <= n; i++)
            cout << "->" << a[i];
    }
    else {
        if (n > 3)
            cout << a[1];
        for (int i = 2; i <= n - 3; i++)
            cout << "->" << a[i];
        if (n != 3)
            cout << "->";
        cout << "(0->0)->0" << endl;
        return 0;
    }
}