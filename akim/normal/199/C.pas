var a,b,c,d,s,n:int64;
begin
 readln(a,b,c,d);
 n:=0;s:=1;
 while s<=d do
 begin
  s:=s*a+b;
  inc(n);
 end;
 if c-n+1<0 then writeln(0) else writeln(c-n+1);
end.