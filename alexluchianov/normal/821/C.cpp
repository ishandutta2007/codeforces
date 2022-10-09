#include <iostream>
#include <stack>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000000;

int main()
{
  int n;
  cin >> n;
  int result = 0, rm = 0;
  stack<int> st;
  for(int i = 1;i <= 2 * n; i++){
    string op;
    int val;
    cin >> op;
    if(op == "add") {
      cin >> val;
      st.push(val);
    } else{
      ++rm;
      val = rm;
      if(0 < st.size()){
        if(st.top() == val){
          st.pop();
        } else{
          result++;
          while(0 < st.size())
            st.pop();
        }
      }
    }
  }
  cout << result;
  return 0;
}