uses math;
var
  n,m,a,b,ans:longint;
begin
  read(n,m,a,b);

  if b<a*m then
    begin
      ans:=(n div m)*b;
      if (n mod m)*a>b then inc(ans,b)
      else inc(ans,(n mod m)*a);
    end
  else ans:=n*a;
  writeln(ans);
end.