    #include <iostream>
    #include <algorithm>
    #include <iomanip>
    #include <cmath>
    using namespace std;
    int main()
    {
    int n, a, b;
    cin >> n >> a >> b;
    int counter = 0;
    for(int i = 1; i <= n; i++){
        if(a<=i-1&&n-i<=b){
        counter++;
        }
    }
    cout<<counter;


    }