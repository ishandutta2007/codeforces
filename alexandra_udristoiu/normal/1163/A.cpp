#include<iostream>
using namespace std;
int n, m;
int main(){
    cin>> n >> m;
    if(m == 0){
        cout<< 1;
        return 0;
    }
    n--;
    m--;
    cout<< min(n - m, m + 1);
}