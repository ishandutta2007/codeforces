uses math;
var
  s:string;
  a1,a2,a3,a4:longint;
  i:longint;
  ans:longint;
begin
  readln(a1,a2,a3,a4);
  ans:=0;
  readln(s);

  for i:=1 to length(s) do
    case s[i] of
      '1': inc(ans,a1);
      '2': inc(ans,a2);
      '3': inc(ans,a3);
      '4': inc(ans,a4);
    end;
  writeln(ans);
end.