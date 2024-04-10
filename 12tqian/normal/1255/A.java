import java.io.*;
import java.util.*;
 
public class Main {
  public static IO in;
  public static PrintWriter out;
 
  static void init_io(String filename) throws Exception {
    if (filename.equals("")) {
      in = new IO(System.in);
      out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
    } else {
      in = new IO(new FileInputStream(filename + ".in"));
      out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")), true);
    }
  }
 

  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");
    int t = in.nint();
    ArrayList<Integer> arr = new ArrayList<Integer>();
    arr.add(0);
    arr.add(1);
    arr.add(2);
    arr.add(-2);
    arr.add(-1);
    for(int test  = 0; test<t; test++) {
    	long a, b;
    	a = in.nlong();
    	b = in.nlong();
    	long ans = 0;
    	if((a-b)%5 == 0) {
    		ans = Math.abs(a-b)/5;
    		
    	}
    	else {
    		long res = ((b-a)%5 + 5)%5;
    	//	System.out.println(res);
    		ans = 1 + Math.abs(a + arr.get((int) res) - b)/5;
    		if(Math.abs(a-b)<=2) {
    			ans = 1;
    		}
    	}
    	out.println(ans);
    }
    
  }
 
  static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }
 
  static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }
 
    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);
 
    for (int i = 0; i < arr.length; i++) {
      arr[i] = alist.get(i);
    }
  }
 
  static void reverse(long[] arr) {
    for (int i = 0; i < arr.length / 2; i++) {
      long temp = arr[i];
      arr[i] = arr[arr.length - 1 - i];
      arr[arr.length - 1 - i] = temp;
    }
  }
 
  static String atos(long[] arr) {
    String s = Arrays.toString(arr);
    s = s.substring(1, s.length() - 1);
    return s.replace(",", "");
  }
 
  static class IO {
    public BufferedReader in;
    public StringTokenizer tokens;
 
    public IO(InputStream x) throws Exception {
      in = new BufferedReader(new InputStreamReader(x));
      tokens = new StringTokenizer(in.readLine());
    }
 
    int nint() throws Exception {
      return Integer.parseInt(nstr());
    }
 
    long nlong() throws Exception {
      return Long.parseLong(nstr());
    }
 
    double ndouble() throws Exception {
      return Double.parseDouble(nstr());
    }
 
    String nstr() throws Exception {
      if (!tokens.hasMoreTokens()) tokens = new StringTokenizer(in.readLine());
      return tokens.nextToken();
    }
    
    long[] nla(int n) throws Exception {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }
 
  static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    public A f;
    public B s;
 
    public Pair(A a, B b) {
      f = a;
      s = b;
    }
 
    public int compareTo(Pair<A, B> other) {
      int v = f.compareTo(other.f);
      if (v != 0) return v;
      return s.compareTo(other.s);
    }
  }
}