uses math;
var
  a:string;
  b:string;
  i,n,nv,ans:longint;
begin
  readln(n);
  readln(a);
  readln(b);
  ans:=0;

  for i:=1 to n do
    begin
      nv:=abs(ord(a[i])-ord(b[i]));
      ans:=ans+min(nv,abs(10-nv));
    end;

  writeln(ans);
end.