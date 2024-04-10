var n,i,l,r,l0,r0,ro,ans,s:longint;
    u:array[1..5000] of longint;
    c:char;
begin
 readln (n);
 for i:=1 to n do
        begin
         read (c);
         if c='L' then u[i]:=-1;
         if c='R' then u[i]:=1;
        end;
 l:=1;
 r:=n;
 while (u[l]=0) and (l<=n) do inc (l);
 while (u[r]=0) and (r>0) do dec (r);
 if l=n+1 then write (n)
          else
          begin
           if u[l]=1 then ans:=ans+l-1;
           if u[r]=-1  then ans:=ans+n-r;
           if l<>n+1 then
                begin
                 if u[l]=1 then l0:=l
                           else r0:=l;
                 for i:=l+1 to r do
                        begin
                         if u[i]=-1 then
                                begin
                                 if (i-l0) mod 2= 0 then inc (ans);
                                 r0:=i;
                                end;
                         if u[i]=1 then
                                begin
                                 ans:=ans+i-r0-1;
                                 l0:=i;
                                end;
                        end;
                 write (ans);
                end;
          end;
end.