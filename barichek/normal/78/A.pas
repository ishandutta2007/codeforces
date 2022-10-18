uses math;
var
  a:array[1..3]of longint;
  s:string;
  i,j:longint;
begin
  for i:=1 to 3 do
    begin
      a[i]:=0;
      readln(s);
      for j:=1 to length(s) do
        if (s[j]='a') or (s[j]='e') or (s[j]='i') or (s[j]='o') or (s[j]='u')
          then inc(a[i]);
    end;
  if (a[1]<>5) or (a[2]<>7) or (a[3]<>5) then writeln('NO')
  else writeln('YES');
end.