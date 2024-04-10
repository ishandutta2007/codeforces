#include <iostream>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::set<int> st;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++)
        st.insert(a[j]-a[i]);

    std::cout << st.size() << std::endl;
  }

  return 0;
}