uses math;
var
  n,x,y:real;
  i,ans:longint;
begin
  read(n,x,y);
  ans:=0;
  n:=n*y/100;
  while x<n do
    begin
      x:=x+1;
      ans:=ans+1;
    end;
  writeln(ans);
end.