uses math;
var
  s:string;
  i:longint;
function big(c:char):char;
  begin
    if (ord(c)>=65) and (ord(c)<=90) then c:=chr(ord(c)+32);
    exit(c);
  end;
begin
  read(s);
  for i:=1 to length(s) do
    s[i]:=big(s[i]);

  for i:=length(s)-1 downto 1 do
    if s[i]<>' ' then break;

  case s[i] of
    'a','e','i','o','u','y': begin write('YES'); halt; end;
  end;
  writeln('NO');
end.