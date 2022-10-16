import java.io.*;
import java.util.*;
/*
 * 	Author: rahuldugar
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static final int mod=1000000007;
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int t=in.nextInt();
		int k=in.nextInt();
		int arr[]=new int[100001];
		arr[0]=1;
		for(int i=1; i<k; i++)
			arr[i]=1;
		for(int i=k; i<100001; i++)
			arr[i]=(arr[i-1]+arr[i-k])%mod;
		for(int i=1; i<100001; i++)
			arr[i]=(arr[i-1]+arr[i])%mod;
		while(t-->0)
		{
			int a=in.nextInt();
			int b=in.nextInt();
			ans.append((arr[b]-arr[a-1]+mod)%mod+"\n");
		}
		System.out.println(ans);
	}
	static StringBuilder ans=new StringBuilder();
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        
    }
}