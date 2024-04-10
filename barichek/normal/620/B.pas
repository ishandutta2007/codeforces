uses math;
var
  s:ansistring;
  a,b,ans:longint;
  i,j:longint;
begin
  read(a,b);

  for i:=a to b do
    begin
      str(i,s);
      for j:=1 to length(s) do
      case s[j] of
        '0': inc(ans,6);
        '1': inc(ans,2);
        '2': inc(ans,5);
        '3': inc(ans,5);
        '4': inc(ans,4);
        '5': inc(ans,5);
        '6': inc(ans,6);
        '7': inc(ans,3);
        '8': inc(ans,7);
        '9': inc(ans,6);
      end;
    end;

  writeln(ans)
end.