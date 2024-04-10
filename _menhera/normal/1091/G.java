import java.lang.*;
import java.util.*;
import java.math.*;

public final class G2
{
  public static void main(String[] args)
  {
    Solver solver = new Solver();
    solver.solve();
  }
}

class Solver
{
  private Scanner sc;
  ArrayList<BigInteger> f;
  
  ArrayList<BigInteger> l;
  
  public void realize(BigInteger x)
  {
    ArrayList<BigInteger> nl = new ArrayList<>();
    
    for(int i=0; i<l.size(); ++i)
    {
      BigInteger v1 = l.get(i);
      BigInteger A = v1.gcd(x);
      BigInteger B = v1.divide(A);
      if(A.equals(BigInteger.ONE) || B.equals(BigInteger.ONE))
      {
        nl.add(v1); continue;
      }
      if(A.isProbablePrime(100)) f.add(A);
      else nl.add(A);
      if(B.isProbablePrime(100)) f.add(B);
      else nl.add(B);
    }
    
    l = new ArrayList<>(nl);
  }
  public void Factorize(BigInteger N)
  {
    Random rnd = new Random();
    
    
    int CALL = 100;
    for(int i=0; i<CALL; ++i)
    {
      BigInteger x;
      do {
          x = new BigInteger(N.bitLength(), rnd).add(BigInteger.ONE);
      } while (x.compareTo(N) > 0);
      
      BigInteger gn = N.gcd(x);
      if(!gn.equals(BigInteger.ONE))
      {
        ++CALL;
        realize(gn);
      }
      
      BigInteger x2 = x.multiply(x).mod(N);
      System.out.println("sqrt "+x2);
      System.out.flush();
      
      BigInteger y = sc.nextBigInteger();
      
      BigInteger xpy = x.add(y).mod(N);
      BigInteger xmy = x.subtract(y).abs();
      
      if(!xpy.equals(BigInteger.ZERO))
        realize(xpy.gcd(N));
      
      if(!xmy.equals(BigInteger.ZERO))
        realize(xmy.gcd(N));
      
      if(l.size() == 0) return;
    }
  }
  
  public Solver()
  {
    sc = new Scanner(System.in);
    f = new ArrayList();
    l = new ArrayList();
  }
  public void solve()
  {
    BigInteger N = sc.nextBigInteger(); l.add(N);
    Factorize(N);
    System.out.print("! "+f.size());
    for(int i=0; i<f.size(); ++i)
      System.out.print(" "+f.get(i).toString());
    System.out.println("");
  }
}