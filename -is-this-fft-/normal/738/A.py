def main ():
    ogos = ["ogo"]
    for i in range(100):
        ogos.append(ogos[-1] + "go")

    length = input()
    text = input()

    for i in range(99, -1, -1):
        text = text.replace(ogos[i], "***")

    print(text)
main()