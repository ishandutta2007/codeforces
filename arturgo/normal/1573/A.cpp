        #include <iostream>
        using namespace std;
         
        int main() {
           ios_base::sync_with_stdio(false);
           int t;
           cin >> t;
           
           for(int i = 0;i < t;i++) {
              int n;
              cin >> n;
              
              char c;
              
              int s = 0;
              for(int j = 0;j < n - 1;j++) {
                 cin >> c;
                 if(c != '0')
                  s += c + 1 - '0';
              }
              
              cin >> c;
              s += c - '0';
              
              cout << s << endl;
           }
           return 0;
        }