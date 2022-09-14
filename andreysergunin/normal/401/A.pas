var n,x,ans,s,a:int64;
    i:longint;
begin
 read (n,x);
 for i:=1 to n do
        begin
         read (a);
         s:=s+a ;
        end;
 ans:=(abs(s)-1) div x+1;
 if s=0 then write (0)
        else write (ans);
end.