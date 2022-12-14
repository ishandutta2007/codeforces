#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 2; i < 8; i++){
        if (!isprime(i))
            continue;
        cout << i << endl;
        string s;
        cin >> s;
        if (s == "yes"){
            for (int j = i + 1; j <= 100 / i; j++){
                if (isprime(j)){
                    cout << j << endl;
                    string a;
                    cin >> a;
                    if (a == "yes"){
                        cout << "composite" << endl;
                        return 0;
                    }
                }
            }
            cout << i * i << endl;
            string a;
            cin >> a;
            if (a == "yes"){
                cout << "composite" << endl;
                return 0;
            }
            cout << "prime" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;
    return 0;
}