uses math;
var
  a,b:string;
  n,ans:longint;
  i:longint;
begin
  readln(n);
  readln(a);
  ans:=1;
  for i:=1 to n-1 do
    begin
      readln(b);
      if a<>b then inc(ans);
      a:=b;
    end;
  writeln(ans);
end.