uses math;
var
  s:string;
  i:longint;
function big(c:char):char;
  begin
         if (ord(c)>=97) and (ord(c)<=122) then c:=chr(ord(c)-32)
    else if (ord(c)>=65) and (ord(c)<=90) then c:=chr(ord(c)+32);
    exit(c);
  end;

begin
  read(s);

  for i:=2 to length(s) do
    if (ord(s[i])<65) or (ord(s[i])>90) then begin writeln(s); halt; end;
  for i:=1 to length(s) do
    s[i]:=big(s[i]);
  writeln(s);
end.