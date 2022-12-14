#include <iostream>

using namespace std;

bool f(int n){
    if (n == 0)
        return 0;
    if (n % 10 == 8 || n % 10 == -8)
        return 1;
    else
        return f(n / 10);
}
int main (){
    int n;
    cin >> n;
    int cnt = 0, m = n;
    for(int i = 1; i <= 1000; i++){
        cnt ++;
        m += i;
        if (f(m) == 1)
            break;
        else
            m = n;
    }
    cout << cnt << endl;
}