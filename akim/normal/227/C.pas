var z,k:int64;
    n,m:longint;
begin
 readln(n,m);
 z:=1;k:=3;
 while n>0 do
 begin
  if n mod 2=1 then z:=(z*k)mod m;
  n:=n div 2;k:=(k*k)mod m;
 end;
 z:=z-1;if z<0 then z:=z+m;
 writeln(z);
end.