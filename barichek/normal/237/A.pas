uses math;
var
  a,b:string;
  n,ans,fula:longint;
  i:longint;
begin
  readln(n);
  fula:=1;
  ans:=1;

  readln(a);
  for i:=1 to n-1 do
    begin
      readln(b);
      if a=b then inc(ans)
      else begin fula:=max(fula,ans); ans:=1; end;
      a:=b;
    end;
  fula:=max(fula,ans);
  writeln(fula);
end.