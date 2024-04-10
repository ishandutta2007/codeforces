var s:string;
    x:array['A'..'Z']of longint;
    c:char;
    i:integer;
begin
 readln(s);
 for i:=1 to length(s) do
  inc(x[s[i]]);
 readln(s);
 for i:=1 to length(s) do
  inc(x[s[i]]);
 readln(s);
 for i:=1 to length(s) do
  dec(x[s[i]]);
 for c:='A' to 'Z' do
  if x[c]<>0 then begin writeln('NO');halt(0);end;
 writeln('YES');
end.