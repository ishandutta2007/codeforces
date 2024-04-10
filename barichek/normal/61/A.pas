uses math;
var
  s1,s2:string;
  i:longint;
begin
  readln(s1);
  readln(s2);

  for i:=1 to length(s1) do
    write((ord(s1[i])-48+ord(s2[i])-48)mod 2);
end.