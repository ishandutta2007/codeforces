uses math;
var
  s:string;
  a,b:longint;
  i,j:longint;
begin
  a:=0;
  b:=0;

  for j:=1 to 8 do
    begin
    readln(s);
    for i:=1 to 8 do
      begin
        if s[i]='Q' then inc(a,9);
        if s[i]='R' then inc(a,5);
        if s[i]='B' then inc(a,3);
        if s[i]='N' then inc(a,3);
        if s[i]='P' then inc(a);
        if s[i]='q' then inc(b,9);
        if s[i]='r' then inc(b,5);
        if s[i]='b' then inc(b,3);
        if s[i]='n' then inc(b,3);
        if s[i]='p' then inc(b);
      end;
    end;
  if a=b then writeln('Draw');
  if a>b then writeln('White');
  if a<b then writeln('Black');
end.