import java.util.*;
import java.io.*;
 
public class Main
{
	static int temp;
	static int p;
/*static int min(int a, int b, int c)
	{
		return Math.min(a, Math.min(b, c));
	}
	static int max(int a, int b, int c)
	{
		return Math.max(a, Math.max(b, c));
	}
	static int max(int b, int c)
	{
		return Math.max(b, c);
	}
	static int min(int b, int c)
	{
		return Math.min(b, c);
	}*/
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int m=in.nextInt();
		String s=in.next();
		char[] a=s.toCharArray();
		int l,r;
		char c1,c2;
		for(int i=0; i<m; i++)
		{
			l=in.nextInt()-1;
			r=in.nextInt();
			c1=in.next().charAt(0);
			c2=in.next().charAt(0);
			for(int j=l; j<r; j++)
				if(a[j]==c1)
					a[j]=c2;
			
		}
		System.out.println(a);
        in.close();
	}
	static long findit(int n,int a)
	{
		if(n!=0)
		return (long)(Math.pow(10, (Math.floor(Math.log(n)/Math.log(9))))*(n%9)*(Math.pow(10,a)+1)+findit(n/9,a+1))%p;
		return 0;
	}
	static StringBuilder ans=new StringBuilder();
	static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	        StringTokenizer st;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String next() throws IOException
	        {
	        	while(st==null||!st.hasMoreElements())
	        	{
	        		try
	        		{
	        			st=new StringTokenizer(readLine());
	        		}
	        		catch(IOException e)
	        		{
	        			e.printStackTrace();
	        		}
	        	}
	        	return
	        			st.nextToken();
	        }
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[64]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
}