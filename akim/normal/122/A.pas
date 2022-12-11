var a:longint;
begin
 readln(a);
 if (a mod 4=0)or
    (a mod 7=0)or
    (a mod 44=0)or
    (a mod 47=0)or
    (a mod 74=0)or
    (a mod 77=0)or
    (a mod 444=0)or
    (a mod 447=0)or
    (a mod 474=0)or
    (a mod 477=0)or
    (a mod 744=0)or
    (a mod 747=0)or
    (a mod 774=0)or
    (a mod 777=0) then writeln('YES') else writeln('NO');
end.