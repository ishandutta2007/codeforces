  var n,k,l,r,s,a:int64;

begin
read (n,k);
n:=n-1;
s:=k*(k-1) div 2;
k:=k-1;
if s<n then write ('-1')
    else
        begin
         if n=0 then write ('0')
         else
         begin
         l:=1;
         r:=k;

         while r-l>1 do
             begin
              a:=(l+r)div 2;
              if (a+k)*(k-a+1) div 2 > n then l:=a
                                         else r:=a;
             end;

         if (r+k)*(k-r+1) div 2= n then write (k-r+1)
                                   else write (k-r+2);
         end;
        end;
end.