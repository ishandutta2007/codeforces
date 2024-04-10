    #include <iostream>
    #include <algorithm>
    #include <iomanip>
    #include <cmath>
    using namespace std;
    int main()
    {
      int n, p = 0;
      cin >> n;
     float counter=0;
      for(int i = 0; i < n; i++){
        cin >> p;
        counter += p;
      }

      cout<<counter/n;

    }