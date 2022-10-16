import java.util.*;
import java.io.*;
 
public class Main 
{
	public static void main(String[] args) throws IOException
	{	
		Reader in=new Reader();
		int h=in.nextInt();
		int tree[]= new int[h+1];
		StringBuilder l1=new StringBuilder(),l2=new StringBuilder();
		for(int i=0; i<=h; i++)
		{
			tree[i]=in.nextInt();
		}
		boolean done=false;
		int[] pretree=new int[h+1];
		pretree[0]=tree[0];
		for(int i=1; i<=h; i++)
			pretree[i]=pretree[i-1]+tree[i];
		l1.append("0 ");
		l2.append("0 ");
		for(int i=1; i<=h; i++)
		{
			if(tree[i-1]==1||done||tree[i]==1)
			{
				for(int j=0; j<tree[i]; j++)
				{
					l1.append(pretree[i-1]+" ");
					l2.append(pretree[i-1]+" ");
				}
			}
			else 
			{
				for(int j=0; j<tree[i]; j++)
					l1.append(pretree[i-1]+" ");
				l2.append(pretree[i-1]+" ");
				for(int j=1; j<tree[i]; j++)
					l2.append((pretree[i-1]-1)+" ");
				done=true;
			}
		}
		if(done)
		{
			System.out.println("ambiguous");
			System.out.println(l1);
			System.out.println(l2);
		}
		else
			System.out.println("perfect");
		in.close();
	}
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