#include <iostream>

using namespace std;

const int maxn = 1e6 + 100;

int a[maxn];

int main (){
    ios_base::sync_with_stdio(false);
	int n, sum = 0;
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1)
        cout << "First" << endl;
    else {
        for (int i = 0; i < n; i++){
            if (a[i] % 2 == 1){
                cout << "First" << endl;
                return 0;
            }
        }
        cout << "Second" << endl;
    }
}