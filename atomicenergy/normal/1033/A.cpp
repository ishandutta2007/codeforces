#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if((c > a) ^ (e > a)){
    	cout << "NO" << endl;
    	return 0;
    }
    if((d > b) ^ (f > b)){
    	cout << "NO" << endl;
    	return 0;
    }
    //if((c+d > a+b) ^ (e+f > a+b)){
    //	cout << "NO" << endl;
    //	return 0;
    //}
    //if((c-d > a-b) ^ (e-f > a-b)){
    //	cout << "NO" << endl;
    //	return 0;
    //}
    cout << "YES" << endl;
    return 0;

}